import java.util.Scanner;
class Main{
    public static void main(String[]Args){
        Scanner sc = new Scanner(System.in);
        char arr[][] = new char [3][3];
         System.out.println("a\t|b\t|c\nd\t|e\t|f\ng\t|h\t|i");
        for(int i=0;i<9;i++){
            if(i%2==0){
            System.out.print("X Position : ");
            char n = sc.next().charAt(0);
            if(n == 'a'){
            arr[0][0] = 'X';
            }
            if(n == 'b'){
            arr[0][1] = 'X';
            }
            if(n == 'c'){
            arr[0][2] = 'X';
            }
            if(n == 'd'){
            arr[1][0] = 'X';
            }
            if(n == 'e'){
            arr[1][1] = 'X';
            }
            if(n == 'f'){
            arr[1][2] = 'X';
            }
            if(n == 'g'){
            arr[2][0] = 'X';
            }
            if(n == 'h'){
            arr[2][1] = 'X';
            }
            if(n == 'i'){
            arr[2][2] = 'X';
            }
            }
            else{
             System.out.print("O Position : ");
            char n = sc.next().charAt(0);
            if(n == 'a'){
            arr[0][0] = 'O';
            }
            if(n == 'b'){
            arr[0][1] = 'O';
            }
            if(n == 'c'){
            arr[0][2] = 'O';
            }
            if(n == 'd'){
            arr[1][0] = 'O';
            }
            if(n == 'e'){
            arr[1][1] = 'O';
            }
            if(n == 'f'){
            arr[1][2] = 'O';
            }
            if(n == 'g'){
            arr[2][0] = 'O';
            }
            if(n == 'h'){
            arr[2][1] = 'O';
            }
            if(n == 'i'){
            arr[2][2] = 'O';
            }   
            }
            System.out.println(arr[0][0]+"\t|"+arr[0][1]+"\t|"+arr[0][2]+ "\n"+arr[1][0]+"\t|"+arr[1][1]+"\t|"+arr[1][2]+"\n"+arr[2][0]+"\t|"+arr[2][1]+"\t|"+arr[2][2]);
            if((arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X') ||(arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X') || (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')||(arr[2][0] == 'X' && arr[1][1] == 'X' && arr[0][2] == 'X')||(arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X')||(arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X')||(arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X')||(arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X')){
            System.out.println(" X is the Winner !!");
            break;
            }
            if((arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O') ||(arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O') || (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')||(arr[2][0] == 'O' && arr[1][1] == 'O' && arr[0][2] == 'O')||(arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O')||(arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O')||(arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O')||(arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O')){
                System.out.println(" O is the Winner !!");
                break;
            }
        }
    }
}
