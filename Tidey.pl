#!/usr/bin/perl

use LWP::Simple;

my $url = 'https://api.sunrise-sunset.org/json?lat=-33.79&lng=151.02';

my $content = get $url;
die "Couldn't get $url" unless defined $content;

print "$content\n";
