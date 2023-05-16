using DataFinder.Model;
using System.Collections.Generic;
using System.Linq;
namespace DataFinder.Extensions
{
    public class DataHandleExtension
    {
        public static List<DataModel> MultiThreadedSort(List<DataModel> datas, string prop)
        {
            if (prop == "Email")
                return datas.AsParallel().OrderBy(x => x.Email).ToList();
            else if (prop == "Id")
                return datas.AsParallel().OrderBy(x => x.Id).ToList();
            else if (prop == "City")
                return datas.AsParallel().OrderBy(x => x.City).ToList();
            else if (prop == "Age")
                return datas.AsParallel().OrderBy(x => x.Age).ToList();
            else
                return datas.AsParallel().OrderBy(x => x.Name).ToList();
        }
        public static List<DataModel> MultiThreadedSearch(List<DataModel> datas, string searchText)
        {
            return datas.AsParallel().Where(x => x.Email.Contains(searchText)
                            || x.Id.ToString().Contains(searchText)
                            || x.City.Contains(searchText)
                            || x.Name.Contains(searchText)
                            || x.Age.ToString().Contains(searchText)).ToList();
        }
        public static List<DataModel> SequentialSort(List<DataModel> datas, string prop)
        {
            if (prop == "Email")
                return datas.OrderBy(x => x.Email).ToList();
            else if (prop == "Id")
                return datas.OrderBy(x => x.Id).ToList();
            else if (prop == "City")
                return datas.OrderBy(x => x.City).ToList();
            else if (prop == "Age")
                return datas.OrderBy(x => x.Age).ToList();
            else
                return datas.OrderBy(x => x.Name).ToList();
        }

        public static List<DataModel> SequentialSearch(List<DataModel> datas, string searchText)
        {
            return datas.Where(x => x.Email.Contains(searchText)
                            || x.Id.ToString().Contains(searchText)
                            || x.City.Contains(searchText)
                            || x.Age.ToString().Contains(searchText)).ToList();
        }
    }
}

