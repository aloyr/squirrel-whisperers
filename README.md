# Squirrel Whisperers
The official [Squirrel Whisperers Drupal 7 website](http://ryansmiller.com/squirrel-whisperers). See below for instructions on how to install the site locally.

## Installation Requirements
- Drush
- Git

## Installing the Squirrel Whisperers website on your local machine using the shell executable file

You can quickly build a local copy of the website by running the *sw_install.sh* script, found in the local_install directory.  On Linux, you can run the script by

	sudo ./sw_install.sh

It will ask you for the Git install directory, the Drupal install directory and the desired site name (can be anything you want).  Symlinks will be created to allow you to work out of the Git repository folder.  By default the Drupal administrator account username is "user" and the password "pass".

## Installing the Squirrel Whisperers website on your local machine manually
1. Install Drupal.  See <https://www.drupal.org/documentation/install/download> for instructions.
2. On your local install, download and enable the [Features module](https://www.drupal.org/project/features).
3. Clone the Git repository.  The URL needed to checkout is <https://github.com/thepolyglot/squirrel-whisperers.git>.  Ideally you will want to have your repository somewhere outside of the main Drupal install.
4. Make symbolic links to reference the theme and module directories. If you’re in a rush, you can skip this step and manually copy the contents of modules and themes to your sites/all directory.
5. Copy the contents of the local_install/libraries/jsonpath to yoursite/sites/all/libraries directory.
6. Return to the Drupal UI and go to *Administration > Modules*. Enable all modules under the Squirrel Whisperers package.
7. Go to Appearance and enable the Zen theme (if you don't see it, get it [here](https://www.drupal.org/project/features)) and the Squirrel Whisperers sub-theme.
8. Go to *Appearance > Blocks* and disable the powered-by, help, navigation, management and login blocks.
9. Go to *Configuration > Site* Information and change the front page to */front* and the slogan to something you like.

## Adding the Main Menu
Unfortunately the items in the Main Menu need to be added manually. Because they are anchor links, I’ve had some difficulty getting them to register in the site install. You can add them by going to *Menus > Main Menu* and adding the following links:
- Discography ["<front>#discography"]
- Music Videos ["<front>#music-videos")
- Twitter ["<front>#twitter"]

## Importing Songs
You’ll notice that there’s no content under the discography section.  That’s because this content has to be imported and you have the option to add the songs you wish from the iTunes API.  Go to http://yoursite/import and then select the Songs importer.  Enter a feed URL from iTunes.  For quick tests, use https://itunes.apple.com/search?term=metallica&entity=song

## Changing Youtube Videos
You can also change the source of the Youtube videos.  To do so, edit the Youtube Block under *Structure > Blocks* and follow the directions.
