#!/usr/bin/perl

use strict;
use warnings;

use LWP::Simple;
use JSON;
use Data::Dumper;

my $url = 'https://api.sunrise-sunset.org/json?lat=-33.79&lng=151.02&formatted=0';
my $json = get $url || die "Couldn't get $url";

my $hash = from_json($json);
die "error received in sunset/sunrise data.\n\n$json" unless $hash->{'status'} eq "OK";

print  Dumper($hash) . "\n";

print $hash->{'results'} . "\n";

print $hash->{'results'}{'sunset'} . "\n";
my $sunset  = $hash->{'results'}{'sunset'};
my $sunrise = $hash->{'results'}{'sunrise'};

print "Sunrise: $sunrise\tSunset: $sunset\n\n";
