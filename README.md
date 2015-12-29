## SETUP

Use [CocoaPods](https://github.com/CocoaPods/CocoaPods), [Carthage](https://github.com/carthage/carthage) or [Set up manually](#setting-up-manually)

### CocoaPods

1. Add Innometrics to your project's `Podfile`:

	```ruby
	target :MyApp do
	  # your app dependencies
	  pod 'Innometrics', :git => 'https://github.com/Innometrics/iOS-SDK.git', :tag => 'v0.3'
	end
	```

2. Run `pod update` or `pod install` in your project directory.

### Carthage

1. Add Innometrics to your project's `Cartfile`

    ```
    github "Innometrics/iOS-SDK" ~> 0.3
    ```

2. Run `carthage update` in your project directory
3. Drag `Innometrics.framework` and `PixateFreestyle.framework` (located in Carthage/Build/iOS/) into your application’s Xcode project, and add it to your test target(s).
4. A new `Run Script Phase` must be added to copy the framework. The instructions can be found on [Carthage's getting started instructions](https://github.com/carthage/carthage#getting-started)
5. Make sure that both libraries are added to "Embed Frameworks" Build Phase

### Setting up manually

1. Download `Innometrics.framework` and `PixateFreestyle.framework`
2. Drag `Innometrics.framework` and `PixateFreestyle.framework` (located in Carthage/Build/iOS/) into your application’s Xcode project, and add it to your test target(s).
3. A new `Run Script Phase` must be added to copy the framework. The instructions can be found on [Carthage's getting started instructions](https://github.com/carthage/carthage#getting-started)
4. Make sure that both libraries are added to "Embed Frameworks" Build Phase

