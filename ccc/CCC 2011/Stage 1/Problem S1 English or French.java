import java.util.*;
import java.lang.*;

public class ccc11s1 {

	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		
		int entries = s.nextInt();
		int tCount = 0;
		int sCount = 0;
		char test;
		
		s.nextLine();
		
		for(int i = 0; i < entries; i++)
		{
			String phrase = s.nextLine();
			
				
				for(int j = 0;j < phrase.length()-1 ; j++)
				{
					test = phrase.charAt(j);
					if( test == 't' || test == 'T')
						tCount++;
					if( test == 's' || test == 'S')
						sCount++;
					
				}
		}
		
		if(tCount > sCount)
			System.out.println("English");
		else if(sCount >= tCount)
			System.out.println("French");
			
			
			
			
	}
	
}
