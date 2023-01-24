foreach $num (@ARGV){
    $sum=0;
    $original_no = $num;
    until($num==0){
        $digit=$num%10;
        $sum=$sum+$digit;
        $num=int($num/10);
    }
    print ("Sum of digits of $original_no is $sum.\n");
}