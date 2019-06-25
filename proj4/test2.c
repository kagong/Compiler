int a(int i,int j){
    return i + j;
}
void main(void){
    output(a(a(5,6),a(3,4)));
    output(a(a(a(7,8),a(a(5,6),a(3,4))),a(1,2)));
}
