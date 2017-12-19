import java.util.*;
import java.io.*;

public class TandemBicycle
{	
	
	public static void main (String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int q = sc.nextInt();
		int N = sc.nextInt();
		int[] dmoj = new int[N];
		int[] peg = new int[N];
		for (int i=0; i<N; i++){
			dmoj[i] = sc.nextInt();	
		}
		for (int i=0; i<N; i++){
			peg[i] = sc.nextInt();
		}
		int total=0;
		Arrays.sort(dmoj);
		Arrays.sort(peg);
		if (q==1){
			for(int i=0; i<N; i++){
				total+=Math.max(dmoj[i], peg[i]);
			}
		}
		else{
			for(int i=0; i<N; i++){
				total+=Math.max(dmoj[i], peg[N-1-i]);
			}
		}
		System.out.print(total);
	}
}