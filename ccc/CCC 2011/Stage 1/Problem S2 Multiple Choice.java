import java.util.*;
import java.lang.*;

public class ccc11s2 {

	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		
		int entries = s.nextInt();
		
		String[] answers = new String[entries];
		String[] student = new String[entries];
		int correct = 0;
		
		for(int i = 0;i < entries;i++)
		{
			answers[i] = s.next();
		}
		for(int j = 0;j < entries;j++)
		{
			student[j]	= s.next();
		}
		for(int k = 0;k < entries;k++)
		{
			if(answers[k].equals(student[k]))
				correct++;
		}
		
		System.out.println(correct);
		
		
		
		}
	
}
