using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace LevwzWpfApp
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        private Label label;
        void Submit(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Hello, My first windows presentation foundation program");
            label = new Label();
            label.Content = "Enter what you want";
            gird1.Children.Add(label);
            MessageBox.Show(this.processPercentSlider.Value.ToString());
        }
    }
}
