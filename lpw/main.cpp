#include <windows.h> //https://en.wikipedia.org/wiki/Windows.h & https://learn.microsoft.com/en-us/cpp/windows/walkthrough-creating-windows-desktop-applications-cpp?view=msvc-170
#include <tchar.h> //https://learn.microsoft.com/en-us/cpp/text/generic-text-mappings-in-tchar-h?view=msvc-170 windows header file
#include <iostream>
#include <list>
#include <string>
#include "Contact.h" //separate file for Contact class . for readability and code management
using namespace std;

//declares
Contact createContact();
void exportContactsToCsv(list<Contact> contactsBook);
void removeContact(list<Contact>& contactBook, int id);
void updateContact(list<Contact>& contactsBook, int id, string firstName, string lastName, string email, string phoneNumber);

//windows desktop app guide: https://learn.microsoft.com/en-us/cpp/windows/walkthrough-creating-windows-desktop-applications-cpp?view=msvc-170
//sample below is taken from the guide
static TCHAR szWindowClass[] = _T("DesktopApp");
static TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");
HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ LPSTR     lpCmdLine,
   _In_ int       nCmdShow
)
{
   WNDCLASSEX wcex;

   wcex.cbSize = sizeof(WNDCLASSEX);
   wcex.style          = CS_HREDRAW | CS_VREDRAW;
   wcex.lpfnWndProc    = WndProc;
   wcex.cbClsExtra     = 0;
   wcex.cbWndExtra     = 0;
   wcex.hInstance      = hInstance;
   wcex.hIcon          = LoadIcon(wcex.hInstance, IDI_APPLICATION);
   wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
   wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
   wcex.lpszMenuName   = NULL;
   wcex.lpszClassName  = szWindowClass;
   wcex.hIconSm        = LoadIcon(wcex.hInstance, IDI_APPLICATION);

   if (!RegisterClassEx(&wcex))
   {
      MessageBox(NULL,
         _T("Call to RegisterClassEx failed!"),
         _T("Windows Desktop Guided Tour"),
         NULL);

      return 1;
   }

   // Store instance handle in our global variable
   hInst = hInstance;

   // The parameters to CreateWindowEx explained:
   // WS_EX_OVERLAPPEDWINDOW : An optional extended window style.
   // szWindowClass: the name of the application
   // szTitle: the text that appears in the title bar
   // WS_OVERLAPPEDWINDOW: the type of window to create
   // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
   // 500, 100: initial size (width, height)
   // NULL: the parent of this window
   // NULL: this application doesn't have a menu bar
   // hInstance: the first parameter from WinMain
   // NULL: not used in this application
   HWND hWnd = CreateWindowEx(
      WS_EX_OVERLAPPEDWINDOW,
      szWindowClass,
      szTitle,
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT,
      500, 100,
      NULL,
      NULL,
      hInstance,
      NULL
   );

   if (!hWnd)
   {
      MessageBox(NULL,
         _T("Call to CreateWindowEx failed!"),
         _T("Windows Desktop Guided Tour"),
         NULL);

      return 1;
   }

   // The parameters to ShowWindow explained:
   // hWnd: the value returned from CreateWindowEx
   // nCmdShow: the fourth parameter from WinMain
   ShowWindow(hWnd,nCmdShow);
   UpdateWindow(hWnd);

   // Main message loop:
   MSG msg;
   while (GetMessage(&msg, NULL, 0, 0))
   {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }

   return (int) msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   PAINTSTRUCT ps;
   HDC hdc;
   TCHAR greeting[] = _T("Hello, Windows desktop!");

   switch (message)
   {
   case WM_PAINT:
      hdc = BeginPaint(hWnd, &ps);

      // Here your application is laid out.
      // For this introduction, we just print out "Hello, Windows desktop!"
      // in the top left corner.
      TextOut(hdc,
         5, 5,
         greeting, static_cast<int>(_tcslen(greeting))); // TextOut expects an int here but _tcslen returns a size_t. Thus the cast.
      // End application-specific layout section.

      EndPaint(hWnd, &ps);
      break;
   case WM_DESTROY:
      PostQuitMessage(0);
      break;
   default:
      return DefWindowProc(hWnd, message, wParam, lParam);
      break;
   }

   return 0;
}

















// int main() {
//   list<Contact> contactsBook;
//   for (int i = 0; i < 2; i++) { //enter 5 contacts in a row
//     Contact contact = createContact();
//     contactsBook.push_back(contact);
//   }
//
//   for (Contact contact : contactsBook) {
//     cout <<
//       contact.getId() << " " <<
//       contact.getUniqueId() << " " <<
//       contact.getFirstName() << " " <<
//       contact.getLastName() << " " <<
//       contact.getEmail() << " " <<
//       contact.getPhoneNumber() << " " <<
//       contact.getDateCreated() << " " <<
//       contact.getDateUpdated() << endl;
//   }
//
//   //testing contact removal logic
//   removeContact(contactsBook, 1);
//
//   for (Contact contact : contactsBook) {
//     cout << "remove check" <<
//       contact.getId() << " " <<
//       contact.getUniqueId() << " " <<
//       contact.getFirstName() << " " <<
//       contact.getLastName() << " " <<
//       contact.getEmail() << " " <<
//       contact.getPhoneNumber() << " " <<
//       contact.getDateCreated() << " " <<
//       contact.getDateUpdated() << endl;
//   }
//
//   //testing update contact logic
//   updateContact(contactsBook, 2, "Maksis", "", "", "");
//
//   for (Contact contact : contactsBook) {
//     cout << "update check" <<
//       contact.getId() << " " <<
//       contact.getUniqueId() << " " <<
//       contact.getFirstName() << " " <<
//       contact.getLastName() << " " <<
//       contact.getEmail() << " " <<
//       contact.getPhoneNumber() << " " <<
//       contact.getDateCreated() << " " <<
//       contact.getDateUpdated() << endl;
//   }
//
//   exportContactsToCsv(contactsBook); //testing saving all contacts to csv using new methodhelper
//
//   return 0;
// }