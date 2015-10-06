import java.util.*;

class hellooo{
	public static void main(String[] args){
		Scanner test = new Scanner(System.in);
		int a[][] = new int[2][3];
		int sum = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				a[i][j] = test.nextInt();
				sum += a[i][j];
			}
		}
		System.out.println(sum);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				System.out.println(a[i][j]);
			}
		}
		for (int i = 0; i < a.length; i++)
			for (int j : a[i]) {
				System.out.println(9*j);
			}
		
	}
}