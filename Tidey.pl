my $url = 'http://freshair.npr.org/dayFA.cfm?todayDate=current';
  # Just an example: the URL for the most recent /Fresh Air/ show

use LWP::Simple;
my $content = get $url;
die "Couldn't get $url" unless defined $content;

# Then go do things with $content, like this:

if($content =~ m/jazz/i) {
  print "They're talking about jazz today on Fresh Air!\n";
} else {
  print "Fresh Air is apparently jazzless today.\n";
}
