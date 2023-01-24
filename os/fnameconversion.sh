for file in "$@"; do
if [ -f $file ];
then
    ufile=`expr $file | tr '[a-z]' '[A-Z]'`
    if [ -f $ufile ];
    then
        echo "$ufile is already exists."
    else
        mv $file $ufile
        echo "File converted successfully."
    fi
else
    echo "$file does not exists."
fi
done