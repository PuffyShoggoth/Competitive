import java.util.Arrays;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;


public class HiddenPalindromes
{
	public static int palength(int i1, int i2, char[] a)
	{
		int tot=0; 
		if (i1==i2){tot-=1;}
		while(i1>=0 && i2<a.length && a[i1]==a[i2]){
			i1-=1; i2+=1; tot+=2;
		}
		return tot;
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		char[] a = sc.readLine().toCharArray(); 
		int m=palength(0, 0, a);
		for(int i=1; i<a.length; i++){
			m=Math.max(m, Math.max(palength(i, i, a), palength(i-1, i, a)));
		}
		System.out.print(m);
	}
}