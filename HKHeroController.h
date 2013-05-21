#import <Foundation/Foundation.h>

@class SBApplication;
@class SBDisplayStack;

@interface HKHeroController : NSObject

+ (HKHeroController *)sharedInstance;

// iOS 5 + 6
// Applications
- (BOOL)isSpringBoardKey; // Returns a BOOL indicating whether SpringBoard is the key application
- (SBApplication *)keyApplication; // Returns the current key application. If nothing is open, returns SpringBoard
- (NSString *)keyApplicationDisplayID; // Returns the key application's display identifier
- (void)activateApplication:(SBApplication *)app; // Launches a given application
- (void)activateApplicationWithDisplayID:(NSString *)displayID; // Launches a given application from it's display identifier
- (void)deactivateKeyApplicationAnimated:(BOOL)animated; // Closes the key application (if there is one) [NOTE: the animated: parameter only applies to iOS 5 at the moment]
- (void)deactivateKeyApplication; // Closes the key application with animation
- (void)killApplication:(SBApplication *)app removeFromSwitcher:(BOOL)removeFromSwitcher; // Kills a given application and optionally removes it from the switcher
- (void)killApplication:(SBApplication *)app; // Kills a given application and removes it from the switcher
- (void)killApplicationWithDisplayID:(NSString *)displayID;

// Images
- (UIImage *)currentScreenImage; // Returns a UIImage of the current screen
- (UIImage *)iconForApplicationWithDisplayID:(NSString *)displayID size:(int)size; // Returns a UIImage of the specified app's icon. Size: 1 = settings icon, 2 = SpringBoard icon

// Device options
- (void)shutdownDevice; // Power down the device
- (void)rebootDevice; // Restart the device
- (void)respringDevice; // Respring the device
- (void)enterSafeMode; // Put the device into mobile substrate safe-mode
- (void)lockDevice; // Locks the device
- (void)vibrateDevice; // Vibrates the device
- (void)setBrightnessLevel:(float)level; // Sets the screen's brightness level
- (void)openSpotlight; // Opens spotlight search
- (void)toggleSwitcher; // Toggles the switcher on & off
- (void)toggleSiri; // Toggles Siri on & off. If device doesn't have Siri, voice-controls will be toggled
- (void)toggleNotificationCenter; // Toggles notification center
- (void)toggleTorch; // Toggles the device's LED flash-light on & off

// Misc
- (void)showHUDWithImage:(UIImage *)image title:(NSString *)title subtitle:(NSString *)subtitle dismissAfterDelay:(NSTimeInterval)delay; // Shows a standard SBHUDView with a given image

// iOS 5
- (SBDisplayStack *)preActivateDisplayStack; // Returns the preActivate display stack
- (SBDisplayStack *)activeDisplayStack; // Returns the active display stack
- (SBDisplayStack *)suspendingDisplayStack; // Returns the suspending display stack
- (SBDisplayStack *)suspendedEventOnlyDisplayStack; // Returns the suspendedEventOnly display stack

@end