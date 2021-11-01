// XkbGetIndicatorState
#include <X11/XKBlib.h>
#include <X11/Xlib.h>
#include <X11/Xresource.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(unsigned char v) {
    if (v == 0) {
        printf("-");
        return;
    }
    if (v & 128) {
        printf("G");
    }
    if (v & 64) {
        printf("W");
    }
    if (v & 8) {
        printf("A");
    }
    if (v & 4) {
        printf("C");
    }
    if (v & 1) {
        printf("S");
    }
}

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        printf("\tReturns status of latched and locked mods.\n");
        printf("\t\t'-' - no mods active.\n");
        printf("\t\t'S' - 'Shift' active.\n");
        printf("\t\t'C' - 'Control' active.\n");
        printf("\t\t'A' - 'Alt' active.\n");
        printf("\t\t'G' - 'AltGr' active.\n");
        printf("\t\t'W' - 'Windows' active.\n");
        printf("\n");
        return (0);
    }
    int screen;
    Display *dpy;

    dpy = XOpenDisplay(NULL);
    if (!dpy) {
        fprintf(stderr, "unable to connect to display\n");
        return 7;
    }

    screen = DefaultScreen(dpy);
    // unsigned int *mask;
    // int status = XkbGetIndicatorState(dpy, XkbUseCoreKbd, mask);
    XkbStateRec state;
    int status = XkbGetState(dpy, XkbUseCoreKbd, &state);
    if (status > 0) {
        printf("!\n");
        return (status);
    }
    if (argc > 1 && strcmp(argv[1], "-r") == 0) {
        printf("%d %d\n", state.latched_mods, state.locked_mods);
    } else {
        output(state.latched_mods);
        printf(" ");
        output(state.locked_mods);
        printf("\n");
    }
    XCloseDisplay(dpy);
    return 0;
}
