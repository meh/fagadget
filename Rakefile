require 'mkmf'
require 'rake'
require 'rake/clean'

NAME    = 'fagadget'
RELEASE = '0.0.1'

CC      = 'g++'
CFLAGS  = "-Os -Wall -Wextra -pedantic #{`pkg-config --cflags gtk+-2.0`.strip} #{`nspr-config --cflags`.strip} -Itracemonkey/js/src"
LDFLAGS = "-s #{`pkg-config --libs gtk+-2.0`.strip} #{`nspr-config --libs`.strip} -Ltracemonkey/js/src -ljs_static"

SOURCES = FileList['sources/**/*.c']
OBJECTS = SOURCES.ext('o')

CLEAN.include(OBJECTS)
CLOBBER.include(NAME)

task :default => NAME

rule '.o' => '.c' do |t|
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

task :dependencies do
    begin
        have_library('gtk-x11-2.0') or raise 1
        have_library('glib-2.0')    or raise 2
        have_library('cairo')       or raise 3
    rescue
        raise "You're missing some dependencies :("
    end
end

task :compile => [:tracemonkey, :dependencies].concat(OBJECTS)

file NAME => :compile do
    sh "#{CC} #{CFLAGS} #{OBJECTS} -o #{NAME} #{LDFLAGS}"
end
