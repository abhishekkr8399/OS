echo "Enter a string : "
read string
if [ -z $string ]
then
    echo "Null string"
    z=0
else
    z=`expr "$string" : '.*'`
    echo "String length is $z."
fi
if [ $z -ge 6 ]
then
    echo "First 3 characters : "
    z=`expr "$string" : '\(...\).*'`
    echo "$z"
    echo "Last 3 characters : "
    z=`expr "$string" : '.*\(...\)'`
    echo "$z"
else
    echo "Length of the string is less than 6."
fi