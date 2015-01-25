import java.util.*;

public class ccc03s1 {

	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int i = 1;
		int area = 1;
		
		do{
			int steps = s.nextInt();
			
			i = steps;
			area= area+steps;
			
			if(area == 9)//ladders
				area = 34;
			
			else if(area == 40)//ladders
					area = 64;
			
			else if(area == 67)//ladders
					area = 86 ;
			
			else if(area == 54 )//snake
					area = 19;
			
			else if(area == 90)//snake
					area = 48 ;
			
			else if(area == 99)// snake
					area = 77;
			else if(area > 100)
					area = area - steps;
			
			if(area < 101 && i != 0)
			System.out.printf("You are now on square %d\n",area);
			 if(area == 100)
				System.out.println("You Win!");
			
			
		}while(i > 0 && area < 99);
			
		if(area != 100)
		System.out.println("You Quit!");
		
		
		
		
		
		
	}
	
}
