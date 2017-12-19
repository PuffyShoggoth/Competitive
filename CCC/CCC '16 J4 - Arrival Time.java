import java.util.*;
import java.io.*;

public class ArrivalTime{
	public static void main(String[] args) throws IOException
	{
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		char[] left = sc.readLine().toCharArray();
		int time=((left[0]-'0')*10 + (left[1]-'0'))*60 + (left[3]-'0')*10;
		int curt=time;
		int tot=120;
		while(tot>0){
			if((420<=curt && curt<600) || (900<=curt && curt<1140)){
				curt+=20;
			}
			else{curt+=10;}
			tot-=10;
			curt=curt%1440; 
		} 
		System.out.format("%02d:%02d", curt/60, curt%60);
		
	}
}