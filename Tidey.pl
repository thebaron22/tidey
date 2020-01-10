#!/usr/bin/perl

use strict;
use warnings;

use LWP::Simple;
use JSON;
use Data::Dumper;

my $url = 'https://api.sunrise-sunset.org/json?lat=-33.79&lng=151.02&formatted=0';
my $json = get $url || die "Couldn't get $url";

my $hash = from_json($json);

print  Dumper($hash) . "\n";

print $hash->{'results'} . "\n";

print $hash->{'results'}{'sunset'} . "\n";
