// g++ win.c -o win -lX11
#include <stdio.h>
#include <limits.h>
#include <X11/Xlib.h>

int main() {
    Display *dsp = XOpenDisplay(NULL);
    Window root = XRootWindow(dsp, 0);
    
    Atom type;
    int format;
    unsigned long nitems, bytes_after;
    int *current_desktop;
    
    XGetWindowProperty(dsp, root, XInternAtom(dsp, "_NET_CURRENT_DESKTOP", 1),
        0L, LONG_MAX, 0, AnyPropertyType, &type, &format, &nitems, &bytes_after,
        (unsigned char **)&current_desktop);
        
    int ret = current_desktop[0];
    printf("Desktop: %d\n", ret);
    
    XCloseDisplay(dsp);

    return 0;
}
