using DataFinder.Model;

namespace DataFinder.Extension
{
    public class DataReader
    {
        public static List<DataModel> ReadData()
        {
            var data = new List<DataModel>();
            var path = Path.Combine(Directory.GetCurrentDirectory(), "Data", "data.csv");
            using (var reader = new StreamReader(path))
            {
                while (!reader.EndOfStream)
                {
                    var line = reader.ReadLine();
                    var values = line.Split(',');
                    data.Add(new DataModel
                    {
                        Id = int.Parse(values[0]),
                        Name = values[1],
                        City = values[2],
                        Password = values[3],
                        Age = values[4]
                    });
                }
            }
            return data;
        }
    }
}
