import java.util.*;
import java.lang.Math;

public class ccc09s1 {

public static void main(String[] args){
	Scanner s = new Scanner(System.in);
	
	int num1 = s.nextInt(); int num2 = s.nextInt();
	int cool = 0 ;
	
	for(int i = 1; i <= 22; i++)
	{
		int power = (int) Math.pow(i, 6);
		
		if( power >= num1 && power <= num2)
			cool++;
			
		if(i == 22)
			System.out.println(cool);
		
	}
		
	
	
}
	
	
}
