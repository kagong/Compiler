/*
 * CONVERTER to binary (recul
 * 4-> (0-> 0 ->1)
 * lsb first order
 */
void convert(int target){
    if(target != 0){
        output(target - 2*(target/2));
        convert(target/2);
    }
}
void main(void){
    int i;
    int target;
    target = input();
    convert(target);
}
