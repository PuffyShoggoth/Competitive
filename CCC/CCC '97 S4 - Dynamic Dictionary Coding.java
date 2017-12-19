import java.util.*;
import java.lang.*;
import java.io.*;

public class DDC
{
	public static void main (String[] args) throws IOException
	{
		int n; Integer cnt; String s;
		Scanner scan = new Scanner(System.in);
		Map <String, Integer> dict = new HashMap<>();
		n=scan.nextInt(); s=scan.nextLine();
		for(int dnr=0; dnr<n; dnr++){
			dict.clear(); cnt=1;
			s=scan.nextLine();
			while(s.length()>1){
				String [] sa = s.split(" ");
				for(String i: sa){
					if (dict.get(i)==null){
						System.out.print(i+" ");
						dict.put(i, cnt); cnt++;
					}
					else{
						System.out.print(dict.get(i)+" ");
					}
				}
				System.out.println();
				if (!scan.hasNextLine()) break;
				s=scan.nextLine();
			}
			System.out.println();
			
		}
	}
}