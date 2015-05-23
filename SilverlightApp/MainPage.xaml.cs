using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using ADMailSDK.DLL;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using SilverlightApp.Resources;

namespace SilverlightApp
{
    public partial class MainPage : PhoneApplicationPage
    {
        // Constructor
        public MainPage()
        {
            InitializeComponent();

            Loaded += (o, e) =>
                {
                    var service = new ADService();
                    service.ShowSomeText();
                };

        }
    }
}