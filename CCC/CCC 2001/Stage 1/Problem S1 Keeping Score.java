import java.util.*;
import java.lang.*;

public class ccc01s1 {

	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		
		String input = s.next();
		
		int clubs = 0,diamonds = 0,hearts = 0,spades = 0,total = 0;
		String[]sections = new String[4];
		
		sections[0] = input.substring(input.indexOf('C'), input.indexOf('D'));
		sections[1] = input.substring(input.indexOf('D'), input.indexOf('H'));
		sections[2] = input.substring(input.indexOf('H'), input.indexOf('S'));
		sections[3] = input.substring(input.indexOf('S'), input.length());
		
		String c = "" ,d = "",h = "",sp = "";
		
		
		for(int i = 0; i < 4;i++)
		{
			
			if(i == 0)
			{
				if(sections[i].length() == 1)
					clubs += 3;
				else if(sections[i].length() == 2)
					clubs += 2;
				else if(sections[i].length() == 3)
					clubs += 1;
			for(int j = 0;j < sections[i].length();j++)
				{
					if(sections[i].charAt(j) == 'A')
						clubs+= 4;
					else if(sections[i].charAt(j) == 'K')
							clubs+= 3;
					else if(sections[i].charAt(j) == 'Q')
							clubs+= 2;
					else if(sections[i].charAt(j) == 'J')
							clubs+= 1;
					
					if(sections[i].charAt(j) != 'C')
					c += sections[i].charAt(j) + " ";
				}
					
			}
			
			else if(i == 1)
			{
				if(sections[i].length() == 1)
					diamonds += 3;
				else if(sections[i].length() == 2)
					diamonds += 2;
				else if(sections[i].length() == 3)
					diamonds += 1;
				for(int j = 0;j < sections[i].length();j++)
					{
					if(sections[i].charAt(j) == 'A')
						diamonds+= 4;
					else if(sections[i].charAt(j) == 'K')
							diamonds+= 3;
					else if(sections[i].charAt(j) == 'Q')
							diamonds+= 2;
					else if(sections[i].charAt(j) == 'J')
							diamonds+= 1;
					
						if(sections[i].charAt(j) != 'D')
						d += sections[i].charAt(j) + " ";
					}
				}
				
				else if(i == 2)
				{
					if(sections[i].length() == 1)
						hearts += 3;
					else if(sections[i].length() == 2)
						hearts += 2;
					else if(sections[i].length() == 3)
						hearts += 1;
					
					for(int j = 0;j < sections[i].length();j++)
					{
						if(sections[i].charAt(j) == 'A')
							hearts+= 4;
						else if(sections[i].charAt(j) == 'K')
								hearts+= 3;
						else if(sections[i].charAt(j) == 'Q')
								hearts+= 2;
						else if(sections[i].charAt(j) == 'J')
								hearts+= 1;
						
						if(sections[i].charAt(j) != 'H')
						h += sections[i].charAt(j) + " ";
					}
				}
				
				else if(i == 3)
				{
					if(sections[i].length() == 1)
						spades += 3;
					else if(sections[i].length() == 2)
						spades += 2;
					else if(sections[i].length() == 3)
						spades += 1;
					
					for(int j = 0;j < sections[i].length();j++)
					{
						if(sections[i].charAt(j) == 'A')
							spades+= 4;
						else if(sections[i].charAt(j) == 'K')
								spades+= 3;
						else if(sections[i].charAt(j) == 'Q')
								spades+= 2;
						else if(sections[i].charAt(j) == 'J')
								spades+= 1;
						
						if(sections[i].charAt(j) != 'S')
						sp += sections[i].charAt(j) + " ";
					}
				}
				
				
			}
					
		total = clubs + diamonds + hearts + spades;
		
		System.out.println("Cards Dealt              Points");
		System.out.println("Clubs " + c +"       " +  clubs);
		System.out.println("Diamonds " + d +"       " +  diamonds);
		System.out.println("Hearts "+ h +"       " +  hearts);
		System.out.println("Spades " + sp +"       " +  spades);
		System.out.println("                       "+ "Total "+ total  );
		
	}
	
}
