using DataFinder.Model;

namespace DataFinder.Extensions
{
    public class DataHandleExtension
    {
        public static List<DataModel> MultiThreadedSort(List<DataModel> datas, string prop)
        {
            List<Task<List<DataModel>>> tasks = new List<Task<List<DataModel>>>();
            int threadCount = Environment.ProcessorCount;
            int batchSize = datas.Count / threadCount;
            int remainingCount = datas.Count;

            for (int i = 0; i < threadCount; i++)
            {
                int startIndex = i * batchSize;
                int count = i == threadCount - 1 ? remainingCount : batchSize;
                remainingCount -= count;

                if (prop == "Email")
                    tasks.Add(Task.Run(() =>
                    {
                        List<DataModel> batch = datas.GetRange(startIndex, count);
                        return batch.OrderBy(x => x.Email).ToList();
                    }));
                else if (prop == "Id")
                    tasks.Add(Task.Run(() =>
                    {
                        List<DataModel> batch = datas.GetRange(startIndex, count);
                        return batch.OrderBy(x => x.Id).ToList();
                    }));
                else if (prop == "City")
                    tasks.Add(Task.Run(() =>
                    {
                        List<DataModel> batch = datas.GetRange(startIndex, count);
                        return batch.OrderBy(x => x.City).ToList();
                    }));
                else if (prop == "Age")
                    tasks.Add(Task.Run(() =>
                    {
                        List<DataModel> batch = datas.GetRange(startIndex, count);
                        return batch.OrderBy(x => x.Age).ToList();
                    }));
                else
                {
                    tasks.Add(Task.Run(() =>
                    {
                        List<DataModel> batch = datas.GetRange(startIndex, count);
                        return batch.OrderBy(x => x.Name).ToList();
                    }));
                }
            }

            List<DataModel> result = new List<DataModel>();
            foreach (var task in tasks)
            {
                result.AddRange(task.Result);
            }

            return result;
        }
        public static List<DataModel> MultiThreadedSearch(List<DataModel> datas, string searchText)
        {
            List<Task<List<DataModel>>> tasks = new List<Task<List<DataModel>>>();
            int threadCount = Environment.ProcessorCount;
            int batchSize = datas.Count / threadCount;
            int remainingCount = datas.Count;

            for (int i = 0; i < threadCount; i++)
            {
                int startIndex = i * batchSize;
                int count = i == threadCount - 1 ? remainingCount : batchSize;
                remainingCount -= count;

                tasks.Add(Task.Run(() =>
                {
                    List<DataModel> batch = datas.GetRange(startIndex, count);
                    return batch.FindAll(x => x.Email.Contains(searchText)).ToList();
                }));
                tasks.Add(Task.Run(() =>
                {
                    List<DataModel> batch = datas.GetRange(startIndex, count);
                    return batch.FindAll(x => x.Id.ToString().Contains(searchText)).ToList();
                }));
                tasks.Add(Task.Run(() =>
                {
                    List<DataModel> batch = datas.GetRange(startIndex, count);
                    return batch.FindAll(x => x.City.Contains(searchText)).ToList();
                }));
                tasks.Add(Task.Run(() =>
                {
                    List<DataModel> batch = datas.GetRange(startIndex, count);
                    return batch.FindAll(x => x.Age.ToString().Contains(searchText)).ToList();
                }));

                tasks.Add(Task.Run(() =>
                {
                    List<DataModel> batch = datas.GetRange(startIndex, count);
                    return batch.FindAll(x => x.Name.Contains(searchText)).ToList();
                }));
            }

            List<DataModel> result = new List<DataModel>();
            foreach (var task in tasks)
            {
                result.AddRange(task.Result);
            }

            return result;
        }
    }
}
