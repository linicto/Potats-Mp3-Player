using System;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Windows.Controls;
using MusicPlayer.Controller;

namespace MusicPlayer
{
    /// <summary>
    /// Interaction logic for LoadingPage.xaml
    /// </summary>
    public partial class LoadingPage : Page
    {
        public LoadingPage()
        {
            InitializeComponent();
            SetupBackgroundWorker();

            int value = CallIncrementNumberOf1FromCppDll(4);
            Console.WriteLine($"found value {value} from 4.");
        }

        [DllImport(@"..\..\..\..\PotatsCpp\x64\Release\PotatsCpp.dll", CallingConvention = CallingConvention.Cdecl)]
        private extern static int IncrementNumberOf1(int number);
        public static int CallIncrementNumberOf1FromCppDll(int number)
        {
            return IncrementNumberOf1(number);
        }


        private void SetupBackgroundWorker()
        {
            var backgroundWorker = new BackgroundWorker();
            backgroundWorker.DoWork += new DoWorkEventHandler(WorkerBuildMusicCollection);
            backgroundWorker.RunWorkerCompleted += new RunWorkerCompletedEventHandler(
                NavigateToAlbumPage);
            backgroundWorker.RunWorkerAsync();
        }

        private void NavigateToAlbumPage(object sender, RunWorkerCompletedEventArgs e)
        {
            var loadingPageUri = new Uri("UI/MainMenuPage.xaml", UriKind.Relative);
            NavigationService.Navigate(loadingPageUri);
        }

        private void WorkerBuildMusicCollection(object sender, DoWorkEventArgs e)
            => MusicLoader.BuildMusicCollection();
    }
}