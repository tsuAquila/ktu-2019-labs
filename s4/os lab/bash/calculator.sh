add() {
    echo "Sum is $(($1 + $2))."
}
sub() {
    echo "Difference is $(($1 - $2))."
}
mult() {
    echo "Product is $(($1 * $2))."
}
div() {
    echo "Quotient is $(($1 / $2))."
}
mod() {
    echo "Remainder is $(($1 % $2))."
}

echo "Enter operands A & B"
echo -n "A: "
read a
echo -n "B: "
read b
echo -n "Enter operation (+ - x / %): "
read op

case $op in
+)
    add a b
    ;;
-)
    sub a b
    ;;
x)
    mult a b
    ;;
/)
    div a b
    ;;
%)
    mod a b
    ;;
esac
