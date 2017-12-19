import java.util.*;

public class DontPassMeTheBall {
	static Scanner sc=new Scanner(System.in);
	public static void main(String args[]){
	int hs=sc.nextInt();
	int tt=0;
	for(int i=3; i<hs; i++){
		for(int j=2; j<i; j++){
			for(int k=1; k<j; k++){
				tt+=1;
			}
		}
	}
	System.out.printf("%d", tt);
	}
}