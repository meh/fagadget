require 'mkmf'
require 'rake'
require 'rake/clean'

def to_library (name)
    "lib#{name}.so"
end

NAME    = 'fagadget'
RELEASE = '0.0.1'

CC      = 'g++'
CFLAGS  = "-Os -Wall -Wextra -Wno-long-long -pedantic #{`pkg-config --cflags gtk+-2.0`.strip} #{`nspr-config --cflags`.strip} -Itracemonkey/js/src -Iinclude"
LDFLAGS = "#{`nspr-config --libs`.strip} -Ltracemonkey/js/src -ljs_static"

SOURCES = FileList['sources/**/*.cpp']
OBJECTS = SOURCES.ext('o')

MODULE_CFLAGS  = "-Os -Wall -Wextra -Wno-long-long -pedantic -Iinclude #{`nspr-config --cflags`.strip}"
MODULE_LDFLAGS = "#{`nspr-config --libs`.strip} -export-dynamic"

MODULES = {
    'gtk' => {
        :dependencies => ['gtk-x11-2.0', 'glib-2.0', 'cairo'],
        :cflags       => `pkg-config --cflags gtk+-2.0`.strip,
        :ldflags      => `pkg-config --libs gtk+-2.0`.strip,
    },
}

MODULES_OBJECTS = MODULES.map {|name, data|
    "modules/#{to_library(name.to_s)}"
}

CLEAN.include(OBJECTS)
CLOBBER.include([NAME] + MODULES_OBJECTS)


if ENV['DEBUG']
    CFLAGS        << ' -g3'
    MODULE_CFLAGS << ' -g3'
else
    LDFLAGS << ' -s'
end

task :default => NAME

rule '.o' => '.cpp' do |t|
    sh "#{CC} #{CFLAGS} -o #{t.name} -c #{t.source}"
end

task :tracemonkey do
    if !(`hg --version` rescue nil)
        raise 'You need mercurial installed.'
    end

    dir = Dir.pwd

    if !File.exists?('tracemonkey')
        sh 'hg clone http://hg.mozilla.org/tracemonkey/'

        Dir.chdir('tracemonkey/js/src')
    else
        Dir.chdir('tracemonkey')

        updated = !`hg pull; hg update;`.match(/no changes found/)

        Dir.chdir('js/src')

        if updated
            File.delete('libjs_static.a')
        end
    end

    if !File.exists?('compile.sh')
        sh 'cp ../../../misc/compile.sh .'
    end

    if !File.exists?('libjs_static.a')
        sh './compile.sh'
    end

    Dir.chdir(dir)
end

task :binary => OBJECTS

MODULES.each {|name, data|
    library = to_library(name.to_s)

    file "modules/#{library}" do
        data[:dependencies].each {|dependency|
            have_library(dependency) or raise "You're missing some dependencies :("
        }

        sh "#{CC} -fpic #{MODULE_CFLAGS} #{data[:cflags]} -shared -Wl,-soname,#{library} -o modules/#{library} modules/#{name}.cpp #{MODULE_LDFLAGS} #{data[:ldflags]}"
    end
}

task :modules => MODULES_OBJECTS

task :compile => [:tracemonkey, :binary, :modules]

file NAME => :compile do
    sh "#{CC} #{CFLAGS} #{OBJECTS} -o #{NAME} #{LDFLAGS}"
end
