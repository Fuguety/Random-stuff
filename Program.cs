public class Exercise{

	public class Person{

		public string name;
		public string year;

	}


	public static void Main(){

		try{
			
			Person ps = new Person();

			Console.WriteLine("Welcome! \n");
			Console.WriteLine("What's your name?");

			//Get name
			while(true){

				ps.name = Console.ReadLine();
				if(ps.name.Length > 3)
					break;
				else
					Console.WriteLine("Input a valid name that has more than 3 characters");

			}

			Console.WriteLine("Wich year were you born my friend of the sun?");

			//Get age
			while(true){

				ps.year = Console.ReadLine();
				int realYear = int.Parse(ps.year);
				if(realYear > 1899 && realYear < 2023)
					break;
				else
					Console.WriteLine("Please input a valid year");

			}
				

			int realYearr = int.Parse(ps.year);
			int age = 2023 - realYearr;
			Console.WriteLine("Hello " + ps.name + "you are " + age + " old!");




		}catch(Exception e){
			Console.WriteLine("Erro");
		}

	}



}
