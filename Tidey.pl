#!/usr/bin/perl

use strict;
use warnings;

use Time::Strptime qw/strptime/;
use LWP::Simple;
use JSON;
use Data::Dumper;
use DateTime;
use CGI ':standard';

my $TZ = 'Australia/Sydney';

# North Parramatta
#my $lat = "-33.79";
#my $long = "151.02";

# Sydney
my $lat = "-33.8671390";
my $long = "151.2071140";

my $url = "https://api.sunrise-sunset.org/json?lat=$lat&lng=$long&formatted=0";
my $json = get $url || die "Couldn't get $url";

my $hash = from_json($json);
die "error received in sunset/sunrise data.\n\n$json" unless $hash->{'status'} eq "OK";

print  Dumper($hash) . "\n";

print $hash->{'results'} . "\n";

print $hash->{'results'}{'sunset'} . "\n\n";
my $sunset  = $hash->{'results'}{'sunset'};
my $sunrise = $hash->{'results'}{'sunrise'};

print "Sunrise: $sunrise\tSunset: $sunset\n\n";

$sunrise =~ s/\:(..)$/$1/;
print "$sunrise\n\n";

my $fmt = Time::Strptime::Format->new('%Y-%m-%dT%H:%M:%S%z', { time_zone => $TZ });
($sunrise, my $offset) = $fmt->parse($sunrise);

print "Sunrise epoch: $sunrise\t offset: $offset\n\n";

$sunset =~ s/\:(..)$/$1/;
print "$sunset\n\n";

$fmt = Time::Strptime::Format->new('%Y-%m-%dT%H:%M:%S%z', { time_zone => $TZ });
($sunset, $offset) = $fmt->parse($sunset);

print "Sunset epoch: $sunset\t offset: $offset\n\n";

print "Sunset - Sunrise: " . ($sunset - $sunrise)/3600 . "\n\n";

print "Sunrise local: " . localtime($sunrise) . "\n\n";

my $delta = ($sunset - $sunrise) / 30;
print "Delta: " . $delta / 60 . "\n\n";

for (my $i = $sunrise; $i < $sunset; $i += $delta) {
  print "spirit:\t" . localtime($i) . "\n";
  $i += $delta;
  print "air:\t"    . localtime($i) . "\n";
  $i += $delta;
  print "fire:\t"   . localtime($i) . "\n";
  $i += $delta;
  print "water:\t"  . localtime($i) . "\n";
  $i += $delta;
  print "earth:\t"  . localtime($i) . "\n\n";
}

print "Sunset local: " . localtime($sunset) . "\n\n";

print header,
  start_html(-title=>"Elemental Tides"),
  h1("Elemental Tides"),
  end_html;
