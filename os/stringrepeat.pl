print "Enter a string : ";
$a=<STDIN>;
print "Number of time string need to displayed : ";
chop($b=<STDIN>);
$c=$a x $b;
print "Result is : \n$c";