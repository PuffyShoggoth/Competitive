import java.util.*;

public class TournamentSelection{

    public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            int t=0;
            int n=-1;
            for(int i=0; i<6; i++){
            	String s=sc.nextLine();
            	if(s.charAt(0)=='W'){t+=1;}
            }
            if(t>0){n=3;}
            if(t>2){n=2;}
            if(t>4){n=1;}
            System.out.printf("%d", n);
    }
}