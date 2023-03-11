namespace Help
{
    public class main
    {

        public static void Main()
        {

            var dataBanks = new LiteDB.LiteDatabase("bank.db");

            var collection = dataBanks.GetCollection<Person>("people");

            var people = collection.Query().ToList();

            foreach (var item in people)
            {
                Console.WriteLine(item.Name);
            }

            var person = new Person()
            {
                Id = people.Max(p => p.Id) + 1,
                Name = "Fallen",
                CPF = "123456789",
                BirthDate = DateTime.Parse("01/01/2000")
            };
            
            collection.Insert(person);


        }
    }
}