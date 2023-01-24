echo "Choose your option :(+) for Addition (-) for Subtraction (*) for Multiplication (/) for Division\n"
echo "Enter your choice :"
read ch
echo "Enter the two numbers :"
read a b
case $ch in
'+') y=`expr $a + $b`
 echo "Sum of $a and $b = $y";;
 '-') y=`expr $a - $b`
 echo "Difference of $a and $b = $y";;
 '*') y=`expr $a \* $b`
 echo "Product of $a and $b = $y";;
 '/') y=`expr $a / $b`
 echo "Quotient of $a by $b = $y";;
 *) echo "Invalid choice.";;
esac