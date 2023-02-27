public class Exercise{

	public class Person{

		public string name;
		public int year;
		public int age;

		public int verifyAge(string yearInput){

			int realYear = int.Parse(yearInput);
			return (realYear);

		}

		public int calculateAge(int year){
			
			int age = 2023 - year;
			return (age);

		}
		
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

				string yearInput = Console.ReadLine();
				ps.year = ps.verifyAge(yearInput);
				
				if(ps.year > 1899 && ps.year < 2023)
					break;
				else
					Console.WriteLine("Please input a valid year");

			}
				


			ps.age = ps.calculateAge(ps.year);
			Console.WriteLine("Hello " + ps.name + " you are " + ps.age + " old!");




		}catch(Exception e){
			Console.WriteLine($"Error {e}");
		}

	}



}
