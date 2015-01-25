import java.util.*;
import java.lang.*;

public class ccc10s1 {

	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		
		int entries = s.nextInt();
		String top = "";
		String top2 = "";
		
		
		int topScore = 0;
		int topScore2 = 0;
		int tempScore = 0;
		
		String temp = "";
		int RAM = 0;
		int CPU = 0;
		int DDS = 0;
		
		for(int i = 0;i < entries;i++)
		{
			temp = s.next();
			RAM = s.nextInt();
			CPU = s.nextInt();
			DDS = s.nextInt();
			
			tempScore = 2*RAM + 3*CPU+ DDS;
		
			
			if(tempScore > topScore){
				top2 = top;
				top = temp;
				topScore2 = topScore;
				topScore = tempScore;
				continue;
				
			}
			else if(tempScore == topScore){
					
					if(temp.compareToIgnoreCase(top) < 0){
						
						top2 = top;
						top = temp;
						topScore2 = topScore;
						topScore = tempScore;
						continue;
					}
					

			}
			
			if(tempScore > topScore2 ){
				top2 = temp;
				topScore2 = tempScore;
				
			}
			else if(tempScore == topScore2){
				if(temp.compareToIgnoreCase(top2) < 0)
					top2 = temp;
			}
			
		
		}
		System.out.println(top);
		System.out.println(top2);
		
	}
	
}
