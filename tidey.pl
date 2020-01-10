#!/usr/bin/perl

use strict;
use warnings;

use Time::Strptime qw/strptime/;
use LWP::Simple;
use JSON;
use DateTime;
use HTML::Template;

my $TZ = 'Australia/Sydney';

my $date = '2020-01-11';
# North Parramatta
#my $lat = "-33.79";
#my $long = "151.02";

# Sydney
my $lat = "-33.8671390";
my $long = "151.2071140";

my $url = "https://api.sunrise-sunset.org/json?lat=$lat&lng=$long&date=$date&formatted=0";
my $json = get $url || die "Couldn't get $url";

my $hash = from_json($json);
die "error received in sunset/sunrise data.\n\n$json" unless $hash->{'status'} eq "OK";

my $sunset  = $hash->{'results'}{'sunset'};
my $sunrise = $hash->{'results'}{'sunrise'};


$sunrise =~ s/\:(..)$/$1/;
my $fmt = Time::Strptime::Format->new('%Y-%m-%dT%H:%M:%S%z', { time_zone => $TZ });
($sunrise, my $offset) = $fmt->parse($sunrise);

$sunset =~ s/\:(..)$/$1/;
$fmt = Time::Strptime::Format->new('%Y-%m-%dT%H:%M:%S%z', { time_zone => $TZ });
($sunset, $offset) = $fmt->parse($sunset);

my $delta = ($sunset - $sunrise) / 30;
my %table;

for (my $i = $sunrise; $i < $sunset; $i += $delta) {
  $table{localtime($i)} = "Spirit";
  $i += $delta;
  $table{localtime($i)} = "Air";
  $i += $delta;
  $table{localtime($i)} = "Fire";
  $i += $delta;
  $table{localtime($i)} = "Water";
  $i += $delta;
  $table{localtime($i)} = "Earth";
}

my $htmlStr = <<HTML;
Content-Type: text/html; charset=ISO-8859-1

<!DOCTYPE HTML>
<html>
    <head>
    </head>

    <body>
    <table border=1>
    <TMPL_LOOP name=ElementalTides>  <tr>
        <td><TMPL_VAR name=element /></td>
        <td><TMPL_VAR name=tide /></td>
      </tr>
    </TMPL_LOOP></table>
    </body>
</html>
HTML

my @list = map {{ Element => $table{$_}, tide => $_}} sort keys %table;
my $template = HTML::Template->new(scalarref => \$htmlStr);

$template->param(ElementalTides => \@list);
print $template->output();
