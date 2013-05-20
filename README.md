#libherokit#
----

##Overview##
If you've ever tried making a mobile substrate tweak for iOS, you know just how tedious it can be looking up, finding, and testing SpringBoard related code. In the process of developing my various tweaks and tools, I have thrown together a small library of common SpringBoard & application methods. After some organizing, compatibility checking, and overall fine tuning, I give you libherokit — an iOS 5+ convenience library that just makes life easier.

##Setup##
Getting libherokit ready for use is beyond easy. Simply make sure you have libherokit installed on your iDevice (add it to your control file's depends: line if you plan on deploying to other devices), then just import "HKHeroController.h" into your project and you're ready to go!

##Usage##
###Activate application###
Launch an SBApplication either by passing an SBApplication, or it's display identifier.

    [[HKHeroController sharedInstance] activateApplication:app];
    [[HKHeroController sharedInstance] activateApplicationWithDisplayIdentifier:@"com.mitchtreece.app"];

###Key application###
Returns the current key (open) SBApplication either as an SBApplication, or as it's display identifier. If there is no key application, SpringBoard or it's respective display identifier will be returned.

    [[HKHeroController sharedInstance] keyApplication];
    [[HKHeroController sharedInstance] keyApplicationDisplayID];

You can close (not kill) key applications by calling:

    [[HKHeroController sharedInstance] deactivateKeyApplication];

If you need to quickly ascertain if SpringBoard is visible (or if there is a keyApplication or not) you can call:

    [[HKHeroController sharedInstance] isSpringBoardKey];

This returns a BOOL indicating whether SpringBoard is the key (visible) application (i.e. no apps open).

###Kill application###
Kills a specified SBApplication either by passing an SBApplication, or by it's display identifier.

    [[HKHeroController sharedInstance] killApplication:app];
    [[HKHeroController sharedInstance] killApplicationWithDisplayID:@"com.mitchtreece.app"];

By default, the above methods also remove the application icon from the multitasking switcher. You can override this behavior by calling:

    [[HKHeroController sharedInstance] killApplication:app removeFromSwitcher:NO];

###Image Utilities###
Returns a UIImage of the current screen.

    [[HKHeroController sharedInstance] currentScreenImage];

Returns a UIImage of the specified application's icon. Size : 1 = settings icon size, size : 2 = SpringBoard icon size.

    [[HKHeroController sharedInstance] iconForApplicationWithDisplayID:@"com.mitchtreece.app" size:2];

###Device utilities###
The following methods execute various device-related tasks. They can all be called like this:

    [[HKHeroController sharedInstance] respringDevice];

They are all pretty self-explanatory so I will just list them, not go into detail about them.

>- (void)shutdownDevice
- (void)rebootDevice
- (void)respringDevice
- (void)enterSafeMode
- (void)lockDevice
- (void)vibrateDevice
- (void)setBrightnessLevel:(float)level
- (void)openSpotlight
- (void)toggleSwitcher
- (void)toggleSiri
- (void)toggleNotificationCenter
- (void)toggleTorch

###Display stacks (iOS 5 only)###
These methods return their respective SBDisplayStack. (Note: iOS 6 did away with these, so don't try to use them if you're running firmware greater than iOS 5!)

    [[HKHeroController sharedInstance] preActivateDisplayStack];
    [[HKHeroController sharedInstance] activeDisplayStack];
    [[HKHeroController sharedInstance] suspendingDisplayStack];
    [[HKHeroController sharedInstance] suspendedEventOnlyDisplayStack];

##Future updates##
I plan on adding more functionality to this library as I need & use it myself. :)