# Script to build the Squirrel Whisperers website
#
# Usage:  sudo ./sw_install.sh

#!/bin/bash

# Get the desired Git directory and drupal root directory from the user
echo "Enter where the Git repository should be cloned: "
read repo_install_directory
echo "Enter the directory where Drupal should be installed: "
read drupal_install_directory
echo "Enter the site name: "
read drupal_database

# Vars
INSTALLDIR=$repo_install_directory
DRUPALROOT=$drupal_install_directory
DRUPALDATA=$drupal_database
DRUPALUSER=user
DRUPALPASS=pass
SQLUSER=root
SQLPASS=root
ACCOUNTMAIL=swuser@example.com

printf '\n\n\n\n'
STARTH=$(date +%H)
STARTM=$(date +%M)
STARTS=$(date +%S)
STARTTIME=`expr $STARTM \* 60 + $STARTS`
printf '\n\n\n\n\n-- Starting %s:%s.%s --\n\n' $STARTH $STARTM $STARTS

printf '\n-- Downloading Drupal --\n\n'

cd $DRUPALROOT

# Download Drupal and change name of directory
drush dl drupal --drupal-project-rename=$DRUPALDATA

# Change directory to new site directory
cd $DRUPALROOT/$DRUPALDATA

printf '\n-- Installing Drupal --\n\n'

printf '\n-- *** If you're having difficulty installing Drupal with this script, install a Drupal
instance manually. Then, comment out the install line in the script and run it again.  When prompted,
insert the path to your manual install. *** --\n\n'

# Install Drupal https://www.drupal.org/documentation/install/developers
drush si minimal --db-url=mysql://$SQLUSER:$SQLPASS@localhost/$drupal_database --account-name=$DRUPALUSER --account-pass=$DRUPALPASS --account-mail=$ACCOUNTMAIL --site-name='Squirrel Whisperers' -y

printf '\n-- Setting up Git repository and creating symlinks to custom theme and modules --\n\n'

# Checkout Squirrel Whisperers repo
git clone https://github.com/thepolyglot/squirrel-whisperers.git $INSTALLDIR/$DRUPALDATA

# Create symlink to themes
ln -s $INSTALLDIR/$DRUPALDATA/themes/squirrel_whisperers $DRUPALROOT/$DRUPALDATA/sites/all/themes

# Create symlink to modules
ln -s $INSTALLDIR/$DRUPALDATA/modules/custom $DRUPALROOT/$DRUPALDATA/sites/all/modules/custom

# Copy libraries directory
cp -r $INSTALLDIR/$DRUPALDATA/local_install/libraries $DRUPALROOT/$DRUPALDATA/sites/all/

printf '\n-- Installing feature dependencies --\n\n'

drush en admin_menu ctools feeds feeds_ui feeds_ex features page_manager panels views view_ui -y

drush pm-enable menu field_ui -y

printf '\n-- Installing custom features --\n\n'

# Go to custom features directory
cd sites/all/modules/custom

# Go through each feature and enable
for d in */ ; do
    drush en ${d%/} -y
done

printf '\n-- Installing themes --\n\n'

# Download themes
drush dl zen -y

printf '\n-- Clearing cache --\n\n'

# Clear Drupal cache.
drush cc all

printf '\n-- Managing themes --\n\n'

# Enable the squirrel_whisperers and zen theme
drush pm-enable squirrel_whisperers zen -y

# Enable and set squirrel_whisperers as default theme and seven as admin theme
drush vset theme_default squirrel_whisperers
drush vset admin_theme seven

# Disable the bartik and seven theme
drush pm-disable bartik -y
drush pm-disable seven -y

# Show theme list
drush pm-list --type=theme

printf '\n-- Disable default blocks --\n\n'

# Download drush extras https://www.drupal.org/project/drush_extras
drush dl drush_extras -n

# Disable default powered-by and help blocks
drush block-disable --module=system --delta=powered-by
drush block-disable --module=system --delta=help
drush block-disable --module=system --delta=navigation
drush block-disable --module=system --delta=management
drush block-disable --module=user --delta=login

# Add anchor menu
#drush add-menu-item main-menu "Discography" "<front>#discography" --weight=0
#drush add-menu-item main-menu "Music Videos" "<front>#music-videos" --weight=1
#drush add-menu-item main-menu "Twitter" "<front>#twitter" --weight=2

# Change home page to /front panel
drush vset site_frontpage front

# Change site slogan
drush vset site_slogan "Official Website of the Squirrel Whisperers"

printf '\n-- Clearing cache --\n\n'

# Clear Drupal cache.
drush cc all

# Print Install Time and install complete message.
ENDH=$(date +%H)
ENDM=$(date +%M)
ENDS=$(date +%S)
ENDTIME=`expr $ENDM \* 60 + $ENDS`

TOTALTIME=`expr $ENDTIME - $STARTTIME`
printf '\n-----------------------------------------' 
printf '\nDone.  Total install time: %s seconds. ' $TOTALTIME
printf '\n-----------------------------------------\n\n\n' 
 
