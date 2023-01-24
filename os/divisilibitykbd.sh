echo "Enter the value of n and m: "
read n m
y=`expr $n % $m`
if [ $y -eq 0 ]
then
    echo "$n is divisible by $m."
else
    echo "$n is not divisible by $m."
fi