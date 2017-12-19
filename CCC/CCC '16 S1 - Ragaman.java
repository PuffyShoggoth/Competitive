import java.util.*;
import java.lang.*;
import java.io.*;


public class Ragaman
{
	public static void main (String[] args) throws java.lang.Exception
	{
		String a=null;
		String b=null;
		int anagram=1;
		int used=0;
		int[] letters = new int[26];
		BufferedReader sc= new BufferedReader(new InputStreamReader(System.in));
		a=sc.readLine();
		b=sc.readLine();
		for(int i=0; i<a.length(); i++){
			letters[a.charAt(i)-'a']+=1;
		}
		for(int i=0; i<b.length(); i++){
			if (b.charAt(i)=='*'){used+=1;}
			else if (letters[b.charAt(i)-'a']>0){
				used+=1; letters[b.charAt(i)-'a']-=1;
			}
		}
		if (a.length()!=b.length() || used!=a.length()){
		System.out.print("N");}
		else{System.out.print("A");}
		
	}
}