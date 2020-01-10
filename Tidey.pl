#!/usr/bin/perl

use strict;
use warnings;

use Time::Strptime qw/strptime/;
use LWP::Simple;
use JSON;
use Data::Dumper;

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

my $fmt = Time::Strptime::Format->new('%Y-%m-%dT%H:%M:%S%z', { time_zone => 'Australia/Sydney' });
my ($epoch, $offset) = $fmt->parse('2014-01-01T00:00:00+0000');

print "epoch: $epoch\t offset: $offset\n\n";

$sunset =~ s/\:(..)$/$1/;
print "$sunset\n\n";

$fmt = Time::Strptime::Format->new('%Y-%m-%dT%H:%M:%S%z', { time_zone => 'Australia/Sydney' });
($epoch, $offset) = $fmt->parse($sunset);

print "epoch: $epoch\t offset: $offset\n\n";
