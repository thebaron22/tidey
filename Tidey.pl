my $url = 'fcdac066d289192fc51d8497187c447c4b9891a0';

use LWP::Simple;
my $content = get $url;
die "Couldn't get $url" unless defined $content;

print "$url\n";
