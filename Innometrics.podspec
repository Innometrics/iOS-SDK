Pod::Spec.new do |s|
  s.name          = "Innometrics"
  s.version       = "0.3.2"
  s.platform      = :ios, "8.0"
  s.summary       = "Innometrics Profile Cloud client library for iOS"
  s.author        = { "Innometrics" => "dev-support@innometrics.com" }
  s.homepage      = "https://github.com/Innometrics/iOS-SDK.git"
  s.license       = { :file => 'LICENSE', :type => 'Commercial' }
  s.frameworks    = 'CoreLocation', 'Security', 'MobileCoreServices', 'SystemConfiguration', 'CoreTelephony', 'PixateFreestyle'
  #s.dependency 'Innometrics/pixate-freestyle-ios',  '~> 2.1'
  s.libraries     = 'xml2', 'sqlite3'
  s.source = {
    :git => 'https://github.com/Innometrics/iOS-SDK.git',
    :tag => 'v0.3.2'
  }
  s.ios.vendored_frameworks = 'Innometrics.framework', 'PixateFreestyle.framework'
end