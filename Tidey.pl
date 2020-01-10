#!/usr/bin/perl

use strict;
use warnings;

use Time::Strptime qw/strptime/;
use LWP::Simple;
use JSON;
use Data::Dumper;
use DateTime;

my $TZ = 'Australia/Sydney';
my $lat = "-33.79";
my $long = "151.02";

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

for (my $i = $sunrise; $i < $sunset; $i += $delta) {
  print localtime($i) . "\n";
}

print "Sunset local: " . localtime($sunset) . "\n\n";
