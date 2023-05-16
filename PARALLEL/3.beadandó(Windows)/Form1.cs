using DataFinder.Extensions;
using DataFinder.Model;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3.beadandó_Windows_
{
    public partial class Form1 : Form
    {
        List<DataModel> DataList;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Random random = new Random();
            DataList = Enumerable.Range(0, 100000).Select(x => new DataModel
            {
                Age = random.Next(1, 100),
                Name = Guid.NewGuid().ToString().Split('-').First(),
                City = GetCity(),
                Id = Guid.NewGuid(),
                Email = Guid.NewGuid().ToString().Split('-').First() + "@example.com"
            }).ToList();
            data.Columns.Add("Id", "Id");
            data.Columns.Add("Name", "Name");
            data.Columns.Add("City", "City");
            data.Columns.Add("Age", "Age");
            data.Columns.Add("Email", "Email");
            for (int i = 0; i < DataList.Count; i++)
            {
                data.Rows.Add(DataList[i].Id, DataList[i].Name, DataList[i].City, DataList[i].Age, DataList[i].Email);
            }
            IsParallelTrue.Checked = true;
            name.Checked = true;
        }
        private static string GetCity()
        {
            Random random = new Random();
            int city = random.Next(2);

            if (city % 2 == 0)
                return "Miskolc";
            else
                return "Budapest";
        }

        private void UseButton_Click(object sender, EventArgs e)
        {
            Stopwatch sw = new Stopwatch();
            List<DataModel> result;
            if (IsParallelFalse.Checked)
            {
                result = SequentialSort(sw);
            }
            else
            {
                result = MultiThreadedSort(sw);
            }
            data.Rows.Clear();
            for (int i = 0; i < result.Count; i++)
            {
                data.Rows.Add(result[i].Id, result[i].Name, result[i].City, result[i].Age, result[i].Email);
            }
            timeLabel.Text = sw.Elapsed.TotalMilliseconds.ToString();
        }
        private List<DataModel> MultiThreadedSort(Stopwatch sw)
        {
            List<DataModel> result;
            if (email.Checked)
            {
                sw.Start();
                result = DataHandleExtension.MultiThreadedSort(DataList, "Email");
                sw.Stop();
            }
            else if (name.Checked)
            {
                sw.Start();
                result = DataHandleExtension.MultiThreadedSort(DataList, "Name");
                sw.Stop();
            }
            else if (city.Checked)
            {
                sw.Start();
                result = DataHandleExtension.MultiThreadedSort(DataList, "City");
                sw.Stop();
            }
            else if (age.Checked)
            {
                sw.Start();
                result = DataHandleExtension.MultiThreadedSort(DataList, "Age");
                sw.Stop();
            }
            else
            {
                sw.Start();
                result = DataHandleExtension.MultiThreadedSort(DataList, "Id");
                sw.Stop();
            }
            return result;
        }
        private List<DataModel> SequentialSort(Stopwatch sw)
        {
            List<DataModel> result;
            if (email.Checked)
            {
                sw.Start();
                result = DataHandleExtension.SequentialSort(DataList, "Email");
                sw.Stop();
            }
            else if (name.Checked)
            {
                sw.Start();
                result = DataHandleExtension.SequentialSort(DataList, "Name");
                sw.Stop();
            }
            else if (city.Checked)
            {
                sw.Start();
                result = DataHandleExtension.SequentialSort(DataList, "City");
                sw.Stop();
            }
            else if (age.Checked)
            {
                sw.Start();
                result = DataHandleExtension.SequentialSort(DataList, "Age");
                sw.Stop();
            }
            else
            {
                sw.Start();
                result = DataHandleExtension.SequentialSort(DataList, "Id");
                sw.Stop();
            }
            return result;
        }

        private void SearchButton_Click(object sender, EventArgs e)
        {
            Stopwatch sw = new Stopwatch();
            List<DataModel> result = new List<DataModel>();
            if (IsParallelFalse.Checked)
            {
                sw.Start();
                result = DataHandleExtension.SequentialSearch(DataList, SearcField.Text);
                sw.Stop();
            }
            else
            {
                sw.Start();
                result = DataHandleExtension.MultiThreadedSearch(DataList, SearcField.Text);
                sw.Stop();
            }
            data.Rows.Clear();
            for (int i = 0; i < result.Count; i++)
            {
                data.Rows.Add(result[i].Id, result[i].Name, result[i].City, result[i].Age, result[i].Email);
            }
            timeLabel.Text = sw.Elapsed.TotalMilliseconds.ToString();
        }
    }
}
