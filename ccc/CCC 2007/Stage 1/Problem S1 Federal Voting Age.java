import java.util.*;

public class ccc07s1 {

	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		
		int entries = s.nextInt();
		
		for(int i = 0; i < entries; i++)
		{
			int year = s.nextInt(),month = s.nextInt(),day = s.nextInt();
			
			if(year > 1989)
				System.out.println("No");
			else if (year == 1989 && month == 2 && day > 27)
				System.out.println("No");
			else if(year== 1989 && month > 2 )
				System.out.println("No");
			
			else
				System.out.println("Yes");
			
		}
		
		
		
	}
	
}
