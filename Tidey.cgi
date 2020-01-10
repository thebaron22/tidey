#!/usr/bin/perl
use strict;
use warnings;
use HTML::Template;

my $htmlStr = <<HTML;
Content-Type: text/html; charset=ISO-8859-1

<!DOCTYPE HTML>
<html>
    <head>
    </head>

    <body>
    <table border=1>
    <TMPL_LOOP name=fruits>  <tr>
        <td><TMPL_VAR name=fruit /></td>
        <td><TMPL_VAR name=color /></td>
      </tr>
    </TMPL_LOOP></table>
    </body>
</html>
HTML

my %tbl = (
    orange      => 'orange',
    lime        => 'lime',
    lemon       => 'lemon',
    bannannanna => 'yellow'
);
my @fruits = map {{fruit => $_, color => $tbl{$_}}} keys %tbl;
my $template = HTML::Template->new(scalarref => \$htmlStr);

$template->param(fruits => \@fruits);
print $template->output();
