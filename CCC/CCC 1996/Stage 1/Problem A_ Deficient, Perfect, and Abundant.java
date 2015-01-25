import java.util.*;

public class ccc96s1 {

	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int entries  = s.nextInt();
		
		
		for(int i = 0; i < entries; i++)
		{
			int input = s.nextInt();
			int test = input - 1;
			int j = 1;
			int x = 0;
			
				for(j = 1 ;j < input;j++)
				{
				
					if(input % j == 0)
						x = x+j;
							
					if(j == test && x < input)
						System.out.printf("%d is a deficient number.\n", input);
					
					else if(j==test && x > input)
						System.out.printf("%d is an abundant number.\n",input);
					
					else if(j==test && x ==input)
						System.out.printf("%d is a perfect number.\n",input);
				}
			
		}
		
	}
	
}
